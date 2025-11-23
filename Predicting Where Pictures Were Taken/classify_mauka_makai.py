import torch
import torchvision

import numpy as np
import cv2
import math
import sys
import PIL
import matplotlib.pyplot as plt


# Like ImageFolder but has optional resnet stuff
class ResNetDataset(torchvision.datasets.ImageFolder):
    def __init__(self, device, *args, **kwargs):
        super().__init__(*args, **kwargs)  # Calls __init__ on ImageFolder

        self.device = device

        # resnet helps with transfer learning
        self.resnet = torchvision.models.resnet50(weights='IMAGENET1K_V2')
        self.resnet.fc = torch.nn.Identity() # set final layers to identity function, ie remove layers.  Want to MINIMIZE number of times this is used
        self.resnet = self.resnet.to(self.device)

        self.memoDict = {}

    # Gets the original image at a certain index
    def getOrigImage(self, index):
        (image, label) = super().__getitem__(index)  # Calls __getitem__ on ImageFolder
        return image

    # Gets the item
    def __getitem__(self, index):
        (image, label) = super().__getitem__(index)  # Calls __getitem__ on ImageFolder

        # make sure we're using gpu/cuda here
        # assert (self.device == "cuda")


        if index in self.memoDict:
            newImage = self.memoDict[index]
        else:
            newImage = image
            newImage = torchvision.transforms.functional.pil_to_tensor(newImage)

            newImage = newImage.type(torch.float32)
            # add extra initial dimension (shape(28,) -> shape(1,28)
            newImage = torch.tensor(np.array([newImage.numpy()]))
            #print(newImage.shape)
            self.memoDict[index] = newImage

            # pass image thru resnet50 netowrk and store result in memoDict
            # tell pytorch to NOT calc gradients
        with torch.no_grad():
            newImage = newImage.to(self.device)
            newImage = self.resnet.forward(newImage)
            # print(newImage.shape)


        resultTuple = (newImage, label)
        return resultTuple


class NeuralNetwork(torch.nn.Module):
    def __init__(self, device):
        super().__init__()  # calls init on torch.nn.Module

        self.loss_fn = torch.nn.BCELoss()  # Binary Cross Entropy, the same as NLL but just with two classes
        self.device = device

        self.layers = torch.nn.Sequential(
            # List of layers

            torch.nn.Linear(2048, 256),

            torch.nn.ReLU(),

            torch.nn.Linear(256, 128),

            torch.nn.ReLU(),
            
            torch.nn.Linear(128, 1),

            torch.nn.Sigmoid()

        )
        self.optimizer = torch.optim.Adam(self.parameters())

    def forward(self, instance):
        flatten = torch.nn.Flatten()
        flatInst = flatten(instance)
        output = self.layers(flatInst)
        return output

    def doTrain(self, dataloader):
        self.train()
        batch = -1
        for (instances, labels) in dataloader:
            # get shape of the instance, first num = number of images
            # print(instances.shape)
            batch += 1
            (instances, labels) = (instances.to(self.device), labels.to(self.device))
            pred = self.forward(instances)

            labels = labels.type(torch.float32)
            losses = self.loss_fn(pred[:, 0], labels)

            self.optimizer.zero_grad()
            losses.backward()
            self.optimizer.step()
        print("Epoch complete")

    def classifyProb(self, instance):

        # Only 1 instance at a time
        with torch.no_grad():
            numInstances = instance.shape[0]
            assert (numInstances == 1)

            self.eval()
            pred = self.forward(instance)

            pred = pred[0]  # Gets rid of the extra set of brackets '[['--> '['

            return pred

    def classify(self, instance):
        prob = self.classifyProb(instance)
        maxLabel = 0

        if prob > 0.5:
            maxLabel = 1
            
        return maxLabel


def computeAccuracy(model, test_dataloader, device):
    # Evaluate after each epoch
    numRight = 0
    numWrong = 0
    model.eval() 
    for instances, labels in test_dataloader:
        (instances, labels) = (instances.to(model.device), labels.to(model.device))
        predLabel = model.classify(instances)
        if predLabel == labels[0]:
            numRight += 1
        else:
            numWrong += 1

    accuracy = numRight / (numRight+numWrong)
    return accuracy

device = "cpu"
if torch.cuda.is_available():
    device = "cuda"

train_data = ResNetDataset(device, root="p4dataoutput/train")
val_data = ResNetDataset(device, root="p4dataoutput/val")

train_dataloader = torch.utils.data.DataLoader(train_data, batch_size=64, shuffle=True)

val_dataloader = torch.utils.data.DataLoader(val_data, batch_size=1, shuffle=True)

model = NeuralNetwork(device).to(device)
print(model)

# resnet = torchvision.models.resnet50(weights='IMAGENET1K_V2')
# resnet.fc = torch.nn.Identity() # set final layers to identity function, ie remove layers.  Want to MINIMIZE number of times this is used
# resnet = self.resnet.to(self.device)

epochs = 10
for e in range(epochs):
    model.doTrain(train_dataloader)
    testAccuracy = computeAccuracy(model, val_dataloader, device)
    print("Validation Accuracy", testAccuracy)

shown = 0
for i in range(len(val_data)):
    if shown >= 3:
        break # stop after 3
    instance, trueLabel = val_data[i]
    realImage = val_data.getOrigImage(i)
    prob = model.classifyProb(instance)

    print("Real label:", trueLabel)

    predLabel = model.classify(instance)
    print("Predicted label:", predLabel)
    print("Probability:", prob[0])


    if predLabel != trueLabel:
        fileName = 'realImage_' + str(shown)
        plt.imshow(realImage)
        plt.savefig('failedImages/' + fileName + '.png')
        shown += 1



custom_data = ResNetDataset(device, root="myImages")
for i in range (len(custom_data)):
    instance, label = custom_data[i]
    predicted = model.classifyProb(instance)
    print("Image " + str(i+1) + " Probability:", predicted[0])