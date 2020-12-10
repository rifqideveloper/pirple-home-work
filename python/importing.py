from itertools import count, combinations, permutations
from operator import add, is_not, ge, le, eq, sub, mod
from statistics import mean, median, mode, stdev

print('-' * 15, 'python is easy', '-' * 15, '\n')
print('=' * 10, 'itertools', '=' * 10)
print('>' * 3, 'count(even and Odd)', '<' * 3)


def even_odd(maxnum):
    a = count(start=0, step=2)
    b = []
    c = []
    for num in a:
        b.append(num)
        c.append(num + 1)
        if b[-1] == maxnum:
            break
    print('', b, '=', 'even number', '\n', c, '=', 'odd number')


even_odd(30)
print('>' * 3, 'combination', '<' * 3)


def comb(a=None, b=None, c=None, d=None):
    letter = [a, b, c, d]
    resuld = combinations(letter, 2)
    for item in resuld:
        print(item)


comb('A', 'B', 'C', 'D')
print('>' * 3, 'permutation', '<' * 3)


def perm(a=None, b=None, c=None, d=None):
    letter = [a, b, c, d]
    resuld = permutations(letter, 2)
    for item in resuld:
        print(item)


perm('A', 'B', 'C', 'D')
print('=' * 10, 'statistics', '=' * 10)
lists = [1, 2, 3, 4, 20]
print('>' * 3, 'mean', '<' * 3)
means = mean(lists)
print('average of data:', means)
print('>' * 3, 'median', '<' * 3)
medians = median(lists)
print('middle value of data:', medians)
print('>' * 3, 'mode', '<' * 3)
modes = mode([1, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5])
print('most common value of discrete or nominal data:', modes)
print('>' * 3, 'stdev', '<' * 3)
stdevs = stdev(lists)
print('Sample standard deviation of data:', stdevs)
print('=' * 10, 'operator', '=' * 10)
da = 2
ab = 4
cd = -7
ed = 4
xz = 1.0
print('>' * 3, 'add', '<' * 3)
print(da, '+', ab, '=', add(da, ab))
print('>' * 3, 'is_not', '<' * 3)
print(ab, '!=', ed, is_not(ab, ed))
print('>' * 3, 'ge', '<' * 3)
print(xz, '>=', da, ge(xz, da))
print('>' * 3, 'le', '<' * 3)
print(xz, '>=', da, le(xz, da))
print('>' * 3, 'eq', '<' * 3)
print(ab, '==', ed, eq(ab, ed))
print('>' * 3, 'sub', '<' * 3)
print(cd, '-', ed, '=', sub(cd, ed))
print('>' * 3, 'mod', '<' * 3)
print(da, '%', ab, '=', mod(da, ab))
