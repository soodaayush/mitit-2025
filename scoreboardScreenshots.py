# Problem #4: Scoreboard Screenshots

# Written by Aayush Sood

# Score: 100/100

def check_screenshots(N, K, screenshots):
    indexedScreenshots = [(screenshots[i], i + 1) for i in range(N)]

    indexedScreenshots.sort(key=lambda x: x[0])

    found = False
    for i in range(1, N):
        for j in range(K):
            if indexedScreenshots[i][0][j] < indexedScreenshots[i - 1][0][j]:
                return "NO", []
        if found:
            break

    return "YES", [x[1] for x in indexedScreenshots]


N, K = map(int, input().split())
screenshots = [list(map(int, input().split())) for _ in range(N)]

result, indices = check_screenshots(N, K, screenshots)

print(result)
if result == "YES":
    print(" ".join(map(str, indices)))
