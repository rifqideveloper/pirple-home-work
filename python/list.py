myUniqueList = [222]


#add things to that list
def adUnique():
    x = 333
    if not myUniqueList:
        myUniqueList.append(x)
        print(True)
        print(myUniqueList)
    elif myUniqueList:
        print(False)
        print(myUniqueList)
    return
adUnique()



























