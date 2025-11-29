import numpy as np

def gramSchmidt(X):

    Q = np.array(X, dtype=float, copy=True)
    n, K = Q.shape

    # init R to matrix of 0
    R = np.zeros((K, K), dtype=float)

    for k in range(K):
        # i = k:(K-1) in python indexing
        i = list(range(k, K))

        # R[k, i] = crossprod(Q[:,k], Q[:, i])
        R[k, i] = Q[:, k].dot(Q[:, i])

        # For each j > k, subtract the projection onto Q[:,k]
        for j in i[1:]:
            proj = (R[k, j] / R[k, k]) * Q[:, k]
            Q[:, j] = Q[:, j] - proj

        # Normalize column k
        R[k, k] = np.sqrt(R[k, k])
        Q[:, k] = Q[:, k] / R[k, k]

        # Adjust the remaining R multipliers:
        # R[k, j] = R[k, j] / R[k, k]  for j>k
        if k+1 < K:
            R[k, k+1:K] = R[k, k+1:K] / R[k, k]

    return {'Q': Q, 'R': R}


if __name__ == "__main__":
    X = np.array([
        [1, 1, 1],
        [1, 2, 4],
        [1, 3, 9],
        [1, 4, 16],
        [1, 5, 25]
    ])
    XQR = gramSchmidt(X)

    print(XQR)
