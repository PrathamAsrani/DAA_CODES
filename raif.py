def maxSubArraySum(arr, low, high, r):
    if low == high:
        return arr[low]
    mid = (low+high)//2
    left = maxSubArraySum(arr, low, mid, r)
    right = maxSubArraySum(arr, mid+1, high, r)
    crossSum, sum, lSum, rSum = 0, 0, 0, 0
    startRange, endRange = 0, 0
    for i in range(mid, left-1, -1):
        sum += arr[i]
        if (sum > lSum):
            lSum = sum
            startRange = i

    sum = 0
    for i in range(mid+1, high):
        sum += arr[i]
        if (sum > rSum):
            rSum = sum
            endRange = i
    if(len(r) < 2):
      r.append(startRange)
      r.append(endRange)
    else:
      r[0] = startRange
      r[1] = endRange
    crossSum = lSum + rSum

    if (left > right):
        if (left > crossSum):
            return left
        else:
            return crossSum
    else:
        if (right > crossSum):
            return right
        else:
            return crossSum


arr = [5, -3, 9, 12, -8, 7, 11, -9, 1, -2, 4, 6]
# arr = [-1, -5, 6, -2, -3, 1, 5, 6]

r = []
print(maxSubArraySum(arr, 0, len(arr)-1, r))

for i in range(r[0], r[1]):
  print(arr[i], end = " ")