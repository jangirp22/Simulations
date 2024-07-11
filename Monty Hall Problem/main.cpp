import random
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

simulations = 100000

def simulate_with_switch(n, k):
    arr = [1] * int(k) + [0] * (int(n) - int(k))
    cnt = 0
    for _ in range(simulations):
        ind = random.randint(0, int(n) - 1)
        if arr[ind] == 1:
            ind1 = random.randint(1, int(n) - 2)
            if arr[ind1] == 1:
                cnt += 1
        else:
            ind1 = random.randint(0, int(n) - 3)
            if arr[ind1] == 1:
                cnt += 1
    return cnt / simulations

def simulate_directly(n, k):
    arr = [1] * int(k) + [0] * (int(n) - int(k))
    cnt = 0
    for _ in range(simulations):
        ind = random.randint(0, int(n) - 1)
        if arr[ind] == 1:
            cnt += 1
    return cnt / simulations

def plot():
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    n_range = np.arange(3, 99)
    k_range = np.arange(1, 97)

    N, K = np.meshgrid(n_range, k_range)

    Z = np.zeros_like(N, dtype=float)

    for i in range(len(n_range)):
        for j in range(len(k_range)):
            n = N[i][j]
            k = K[i][j]
            ans1 = ((k * (n - 1)) / (n * (n - 2))) * (k != (n - 1)) + (n / n) * (k == (n - 1))
            ans2 = k / n
            Z[i][j] = ans1 / ans2

    surf = ax.plot_surface(N, K, Z, cmap='viridis')

    ax.set_xlabel('n (Number of doors)')
    ax.set_ylabel('k (Number of doors with cars)')
    ax.set_zlabel('P(win|W)/P(win|T)')

    plt.title('Surface Plot of Probability ratio vs. Number of doors vs. Number of doors with cars')
    plt.show()

def main():
    n = float(input("Enter number of doors :\n"))
    k = float(input("Enter number of doors with cars behind them :\n"))

    if k >= n or n<=2:
        print("Invalid Input, since number of cars can't be equal to or more than number of doors and n can't be less then 3.")
    else:
        print("\n*******************************************\n")
        print("Theoretically expected value - ")
        print("Probability of winning without switching : ", k / n)
        print("Probability of winning with switching : ", (((k * (n - 1)) / (n * (n - 2))) * (k != (n - 1)) + (n / n) * (k == (n - 1))))
        print("\n*******************************************")

        print("\n*******************************************\n")
        print("Simulated value - ")
        ans1 = simulate_directly(n, k)
        print("Probability of winning without switching : ", ans1)
        ans2 =  simulate_with_switch(n, k)
        print("Probability of winning with switching : ", ans2)
        print("\n*******************************************\n")

        plot()

if __name__ == "__main__":
    main()
