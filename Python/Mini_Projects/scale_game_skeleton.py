#/ PLAY IT BACK
# Play back a sequence of notes in a given scale.

import random

class Note:
    def __init__(self, name, color, soundFile):
        """
        A class representing a SINGLE note object. Scales are a separate class.

        :param name: The name of the note (e.g., "C", "D", "B").
        :param color: The color of the note (e.g., "red", "blue").
        :param soundFile: The sound file associated with the note (e.g., "C.wav").
        """

        self.name = name
        self.color = color
        self.soundFile = soundFile


class Scale:
    """
    Class representing a musical scale comprised of Notes.
    """
    def __init__(self, name, root, isMajor = True, skipNotes = False, randomize = False):
        """
        Initialize a Scale object.
        :param name: Name of the scale (e.g., "C Major").
        :param root: The root note of the scale (e.g., "C").
        :param isMajor: Boolean indicating whether the scale is major (True) or minor (False).
        :param randomize: Boolean indicating whether to randomize the order of notes in the scale.
        """
        self.name = name
        self.root = root
        self.root = self.root.upper()  # Ensure the root note is uppercase
        self.isMajor = isMajor
        self.skipNotes = skipNotes
        self.randomize = randomize
        self.notesColorsDict = {
            "C4": "#FF0000",
            "C#4": "#ff5404",
            "D4": "#ff9a00",
            "D#4": "#ffd600",
            "E4": "#d6ff00",
            "F4": "#9aff00",
            "F#4": "#54ff00",
            "G4": "#00ff00",
            "G#4": "#00ff54",
            "A4": "#00ff9a",
            "A#4": "#00ffd6",
            "B4": "#00d6ff",
            "C5": "#009aff",
            "C#5": "#0054ff",
            "D5": "#0000ff",
            "D#5": "#5400ff",
            "E5": "#9a00ff",
            "F5": "#d600ff",
            "F#5": "#ff00d6",
            "G5": "#ff009a",
            "G#5": "#ff0054",
            "A5": "#ff0000",
            "A#5": "#ff5404",
            "B5": "#ff9a00",

        }

        self.notes = self.buildScale()  # Build the scale upon init

    def getBaseScale(self, currOctave):
        """
        Get the base scale for the given root note.
        :param root: The root note (e.g., "C").
        :return: A list of notes representing the base scale.
        """

        # 12 chromatic semitones from C
        baseNotes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']

        maj_intervals = [2, 2, 1, 2, 2, 2, 1] # Whole and half steps for major scale
        min_intervals = [2, 1, 2, 2, 1, 2, 2] # Whole and half steps for minor scale

        if self.root not in baseNotes:
            raise ValueError(f"Invalid root note: {self.root}")

        currIdx = baseNotes.index(self.root)
        currOctave = 4 # starting octave, always assumed to start at 4 because i hate you specifically

        # init scale with root note
        scale = [f"{baseNotes[currIdx]}{currOctave}"]

        # get remaining notes
        intervals = maj_intervals if self.isMajor else min_intervals

        for step in intervals:
            next = currIdx + step

            # if we pass idx 11, enter next octave
            if next >= len(baseNotes):
                currOctave += 1
                next -= len(baseNotes)
            scale.append(f"{baseNotes[next]}{currOctave}")
            currIdx = next
        return scale



    def buildScale(self):
        """
        Build the scale sequence to be played back. If randomize is True, the order of notes will be randomized.
        :return: A list of notes as a scale.
        """
        notes = []
        for note in self.getBaseScale():
            noteName = note
            soundFileName = f"audio/notes/{note}.wav"  # Assuming sound files are named like "C4.wav", "D#4.wav", etc.
            noteColor = self.notesColorsDict.get(note, "#000000")  # Default to black if note color is not found
            newNote = Note(noteName, noteColor, soundFileName)
            notes.append(newNote)

        return notes

    def doredoBuild(self):
        """
        Create a do, do-re-do, do-re-mi-re-do, etc. ascending scale that the player will have to play back.
        :return: A list of lists of notes in the ascending scale pattern.
        """
        notes = self.notes

        if self.skipNotes:
            # select three random notes to skip

            idxToSkip = random.sample(range(len(self.notes)), 3)
            skipAscendingScale = []
            for i in range(len(self.notes)):
                if i not in idxToSkip:
                    skipAscendingScale.append(self.notes[i])

            notes = skipAscendingScale
       
        if self.randomize:
            notes = random.sample(self.notes, len(self.skipNotes))

        ascendingScale = []
        for i in range(len(notes)):
            # we want 0, 0-1-0, 0-1-2-1-0, 0-1-2-3-2-1-0, etc.
            if i == 0:
                pattern = [notes[0]]  # Just the root note for the first pattern
            else:
                pattern = notes[:i+1] + notes[i-1::-1]  # Create the ascending and descending pattern
            ascendingScale.append(pattern)
        

        return ascendingScale

