import math

'''
a = [1, 3, 4, 5, 7, 8, 10, 13, 15, 17]
b = [18, 20, 21, 25, 26, 28, 30]

17 elements total, median should be greater than 8 elements and smaller than 8 elements 
We choose 8 and 25 as pivots
8 is at least bigger than 5 elements and at most bigger than 8 elements
25 is at least bigger than 9 elements max 13 elements
that means the median is smaller than 25
[1, 3, 4, 5, 7, 8, 10, 13, 15, 17]
[18, 20, 21]

We choose 8 and 20
8 is still at least bigger than 5 elements but now max. 6 elements
20 is at least bigger than 7 elements max. 11 elements
This means that 8 and anything under cannot be the median
[10, 13, 15, 17]
[18, 20, 21]

15, 20
15 is at least bigger than 8 elements max. 9 elements
20 is at least bigger than 10 elements max. 11 elements
The median cannot be 20 or anything over
[10, 13, 15, 17]
[18]

15, 18
15 is bigger than at least 8 elements max 8 elements 
18 is bigger than at least 9 elements max. 10 elements

The median must be 15!


a = [10, 20, 30, 40, 50, 180, 190, 200, 210, 220, 230]
b = [1, 2, 3, 181, 182, 183, 191, 192, 240, 250]

180, 183
180 is min bigger than 5 elms, max 10
183 is min bigger than 11 elms, max 16

[10, 20, 30, 40, 50, 180, 190, 200, 210, 220, 230]
[1, 2, 3, 181, 182] 
180, 3
180 is min bigger than 8 elms, max 10
3 is min bigger than 2 elms, max 7

[10, 20, 30, 40, 50, 180, 190, 200, 210, 220, 230]
[181, 182]
180, 182
180 is min bigger than 5 elms, max 6
182 is min bigger than 10 elms, max 15

[190, 200, 210, 220, 230]
[181, 182]
210, 182
210 is min bigger than 13 elms
182 is min bigger than 10 elms max 12

[190, 200]
[181, 182]
200, 182
200 is min. bigger than 12 elms

[190]
[181, 182]
190, 182
190 is min bigger than 11 elms

[181, 182]
182
182 is min bigger than 10 elms, max 15

[181]


This example is an even list, that makes it harder. Now for an element to be the median it should be bigger than either 10 or 11 elements
a = [10, 20, 30, 40, 50, 170, 180, 200, 210, 220, 230]
b = [1, 2, 3, 60, 181, 185, 190, 191, 192, 240, 250]
170, 185
170 is bigger than min 5 elms max 10
185 is bigger than min 11 elms max 16

[170, 180, 200, 210, 220, 230]
[1, 2, 3, 60, 181, 185, 190, 191, 192, 240, 250]
210, 185
210 is min bigger than 14 elms max 20 elms
185 is min bigger than 11 elms max 13 elms

[170, 180, 200]
[1, 2, 3, 60, 181, 185, 190, 191, 192, 240, 250]
180, 185
180 is min bigger than 6 elms max 11 elms
185 is min bigger than 12 elms max 13 elms

[170, 180, 200]
[1, 2, 3, 60, 181, 185] 
180, 60
180 is min bigger than 10 elms max 11 elms
60 is min bigger than 3 elms max 9 elms

[170, 180, 200]
[181, 185]
180, 185
180 is bigger than min 10 elms max 11 elms
185 is bigger than min 12 elms max 16 elms

[170, 180, 200]
[181]
180, 185
180 is bigger than min 10 elms max 10 elms
181 is bigger than min 11 elms max 15

[180, 200]
[181]
180, 181
180 is bigger than min 10 elms max 10 elms
181 is bigger than min 11 elms max 15 elms

[180]
[181]
(181+180)=180.5

'''

# Should be 8
listA = [1, 4, 5, 9, 11, 12, 15] #[1, 2, 3, 8, 9, 15]
listB = [2, 3, 6, 7, 8, 10, 13, 14] # [4, 7, 13, 18, 19, 20, 30]

# Should be 10
listA = [1, 8, 9, 10, 11, 13, 15, 16, 17] 
listB = [2, 3, 5, 6, 7, 12, 14, 18] 

# Should be 180
listA = [10, 20, 30, 40, 50, 180, 190, 200, 210, 220, 230]
listB = [1, 2, 3, 181, 182, 183, 191, 192, 240, 250]

# Should be 181
listA = [10, 20, 30, 40, 50, 180, 190, 200, 210, 220, 230]
listB = [1, 2, 3, 4, 181, 182, 191, 192, 240, 250]


# Should be (180+181)/2
listA = [10, 20, 30, 40, 50, 170, 180, 200, 210, 220, 230]
listB = [1, 2, 3, 60, 181, 185, 190, 191, 192, 240, 250]

l = len(listA) + len(listB)

half = math.floor(l/2) # This many elements are respectively bigger and smaller than the median value

pa = 0
pb = 0
# Stores how much of the start is missing from the lists (parts of the lists get cut off)
aStartLenMissing = 0
bStartLenMissing = 0
# Stores how much of the end is missing from the lists
aEndLenMissing = 0
bEndLenMissing = 0
paMin = 0
pbMin = 0
paMax = math.inf
pbMax = math.inf

firstRun = True # Used to determine if findMedian has been called by itself or not 

# This function runs recursively, each time removing half of one of the lists because those numbers for sure not can be the median
def findMedian(a, b):
    global pa, pb, aStartLenMissing, bStartLenMissing, aEndLenMissing, bEndLenMissing, paMin, pbMin, paMax, pbMax, firstRun

    if firstRun:
        pa = math.floor(len(a)/2) 
        pb = math.floor(len(b)/2)

        aStartLenMissing = 0
        bStartLenMissing = 0
        aEndLenMissing = 0
        bEndLenMissing = 0
        paMin = 0
        pbMin = 0
        paMax = math.inf
        pbMax = math.inf
        firstRun = False
    
    print(a, b)

    if len(a) == 0:
        if pbMin > half:
            newB = b[:pb]
            bEndLenMissing = len(b) - len(newB)
            pb = math.floor(len(b)/2)
            pbMin = bStartLenMissing + pb
            pbMax = bStartLenMissing + pb + aStartLenMissing + aEndLenMissing
            return findMedian([], newB)
        elif pbMax < half:
            newB = b[pb+1:]
            bStartLenMissing = len(b) - len(newB)
            pb = math.floor(len(b)/2)
            pbMin = bStartLenMissing + pb
            pbMax = bStartLenMissing + pb + aStartLenMissing + aEndLenMissing
            return findMedian([], newB)
        elif len(b) == 1:
            firstRun = True
            return b[0]
        elif l % 2 == 0 and len(b) == 2:
            firstRun = True
            return (b[0]+b[1])/2
        return b[pb]
        print("Weird", a, b)
        print(paMin, paMax, pbMin, pbMax)
    elif len(b) == 0:
        if paMin > half:
            newA = a[:pa]
            aEndLenMissing = len(a) - len(newA)
            pa = math.floor(len(a)/2)
            paMin = aStartLenMissing + pa
            paMax = aStartLenMissing + pa + bStartLenMissing + bEndLenMissing
            return findMedian(newA, [])
        elif paMax < half:
            newA = a[pa+1:]
            aStartLenMissing = len(a) - len(newA)
            pa = math.floor(len(a)/2)
            paMin = aStartLenMissing + pa
            paMax = aStartLenMissing + pa + bStartLenMissing + bEndLenMissing
            return findMedian(newA, [])
        elif len(a) == 1:
            firstRun = True
            return a[0]
        elif l % 2 == 0 and len(a) == 2:
            firstRun = True
            return (a[0]+a[1])/2
        return a[pa]
        print("Weird", a, b)

    
    # Set the variables with properties we can obtain from looking at the pivot elements
    # But only update variables if the information that we got is more precise than the information we already had
    if a[pa] < b[pb]:
        paMin = max(paMin, aStartLenMissing + pa) # The a pivot element is at least bigger than this many elements
        paMax = min(paMax, aStartLenMissing + pa + bStartLenMissing + pb) # The a pivot element is maximum bigger than this many elements
        pbMin = max(pbMin, bStartLenMissing + pb + aStartLenMissing + pa+1)
        pbMax = min(pbMax, bStartLenMissing + pb + aStartLenMissing + len(a))
    elif a[pa] > b[pb]:
        paMin = max(paMin, aStartLenMissing + pa + bStartLenMissing + pb+1) # The a pivot element is at least bigger than this many elements
        paMax = min(paMax, aStartLenMissing + pa + bStartLenMissing + len(b)) # The a pivot element is maximum bigger than this many elements
        pbMin = max(pbMin, bStartLenMissing + pb)
        pbMax = min(pbMax, bStartLenMissing + pb + aStartLenMissing + pa)

    print(a[pa], b[pb], aStartLenMissing, bStartLenMissing)
    print(paMin, paMax, pbMin, pbMax)

    # Determine what part of the lists can be ruled out and cut off
    if l % 2 == 0:
        #if (paMin == half-1 == paMax) or (paMin == half == paMax):
        if paMax < half-1:
            newA = a[pa+1:] # We want the new a list to only contain elements bigger than element pa
            aStartLenMissing += len(a)-len(newA)
            pa = math.floor(len(newA)/2) # Choose new pivot now that half of the list is removed
            paMin = 0
            paMax = math.inf
            return findMedian(newA, b)
        elif pbMax < half-1:
            newB = b[pb+1:] # We want the new b list to only contain elements bigger than element pb
            bStartLenMissing += len(b)-len(newB)
            pb = math.floor(len(newB)/2)
            pbMin = 0
            pbMax = math.inf
            return findMedian(a, newB)
        elif paMin > half+1:
            newA = a[:pa] # We want the new a list to only contain elements smaller than element pa
            aEndLenMissing += len(a)-len(newA)
            pa = math.floor(len(newA)/2)
            paMin = 0
            paMax = math.inf
            return findMedian(newA, b)
        elif pbMin > half+1:
            newB = b[:pb] # We want the new b list to only contain elements smaller than element pb
            bEndLenMissing += len(b)-len(newB)
            pb = math.floor(len(newB)/2)
            pbMin = 0
            pbMax = math.inf
            return findMedian(a, newB)
        elif len(a) > pa+2 and paMin == half+1:
            newA = a[:pa+1] # We want the new a list to not contain elements bigger than element pa
            aEndLenMissing += len(a)-len(newA)
            pa = math.floor(len(newA)/2) # Choose new pivot now that half of the list is removed
            paMin = 0
            paMax = math.inf
            return findMedian(newA, b)
        elif len(b) > pb+2 and pbMin == half+1:
            newB = b[:pb+1]
            bEndLenMissing += len(b)-len(newB)
            pb = math.floor(len(newB)/2)
            pbMin = 0
            pbMax = math.inf
            return findMedian(a, newB)
        elif pa > 0 and paMax == half-1:
            newA = a[pa:]
            aStartLenMissing = len(a)-len(newA)
            pa = math.floor(len(newA)/2)
            paMin = 0
            paMax = math.inf
            return findMedian(newA, b)
        elif pb > 0 and pbMax == half-1:
            newB = b[pb:]
            bStartLenMissing = len(b)-len(newB)
            pb = math.floor(len(newB)/2)
            pbMin = 0
            pbMax = math.inf
            return findMedian(a, newB)
    else:
        if paMin == half == paMax: # The median is found
            firstRun = True
            return a[pa]
        elif pbMin == half == pbMax: # The median is found
            firstRun = True
            return b[pb]
        elif paMax < half:
            newA = a[pa+1:] # We want the new a list to only contain elements bigger than element pa
            aStartLenMissing += len(a)-len(newA)
            pa = math.floor(len(newA)/2) # Choose new pivot now that half of the list is removed
            paMin = 0
            paMax = math.inf
            return findMedian(newA, b)
        elif pbMax < half:
            newB = b[pb+1:] # We want the new b list to only contain elements bigger than element pb
            bStartLenMissing += len(b)-len(newB)
            pb = math.floor(len(newB)/2)
            pbMin = 0
            pbMax = math.inf
            return findMedian(a, newB)
        elif paMin > half:
            newA = a[:pa] # We want the new a list to only contain elements smaller than element pa
            aEndLenMissing += len(a)-len(newA)
            pa = math.floor(len(newA)/2)
            paMin = 0
            paMax = math.inf
            return findMedian(newA, b)
        elif pbMin > half:
            newB = b[:pb] # We want the new b list to only contain elements smaller than element pb
            bEndLenMissing += len(b)-len(newB)
            pb = math.floor(len(newB)/2)
            pbMin = 0
            pbMax = math.inf
            return findMedian(a, newB)


print(findMedian(listA, listB))
