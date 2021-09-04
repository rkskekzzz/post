import copy
import random

li = ["jiychoi", "junmkang", "jaewpark", "echung", "ycha", "yesim", "cheolee", "klim", "holee", "yurlee", "keokim", "tkim", "sujilee", "hyojekim", "yeonwlee", "jubaek", "sehyan", "yunselee", "hyeojung", "yko"]
arr = [0] * 20


for j in range(4200):
	result = random.sample(range(0, 20), 3)
	print(result)

	for i in result:
		print(i)
		arr[i] += 1


# temp = copy.deepcopy(arr)
temp = list(arr)
# arr.sort

# print(temp)
print(arr)


# for i in range(3)
# 	print(arr[i])
