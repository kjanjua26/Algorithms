import math # dependencies
from time import time

doc1 = open('doc1.txt', 'r')
doc2 = open('doc2.txt', 'r')

class docDist:
    def __init__(self):
        pass

    def _readFile(self, doc):
        return doc.readlines()  # reads the document line by line.

    def _clean_document(self, doc):
        doc = self._readFile(doc)
        return [x.lower() for x in doc]  # formates the document

    def _tokenzie(self, doc):
        doc = self._clean_document(doc)
        return [x.split(' ') for x in doc]  # tokenizes the document.

    def _freq_count(self, doc):
        doc = self._tokenzie(doc)
        flatten_doc = [x for sublist in doc for x in sublist]  # flatten the lists.
        cache = {}  # initializing a cache to store the frequencies.
        for tok in flatten_doc:
            if tok in cache: cache[tok] += 1  # incrementing the frequency count
            else: cache[tok] = 1
        return cache

    def _dotProd_(self, doc1, doc2):
        Totsum = 0.0
        for key in doc1:
            if key in doc2: Totsum += doc1[key] * doc2[key]  # multiply similar elements.
        return Totsum

    def _cosAngle_(self, doc1, doc2):
        prod = self._dotProd_(doc1, doc2)
        norm = math.sqrt(self._dotProd_(doc1, doc1) * self._dotProd_(doc2, doc2))
        return math.acos(prod / norm)  # computing the cosine angle.


if __name__ == '__main__':
    dist = docDist()
    start = time()
    doc1_cache = dist._freq_count(doc1)
    doc2_cache = dist._freq_count(doc2)
    print("The number of tokens in doc1 are: ",sum(doc1_cache.values()))
    print("The number of tokens in doc2 are: ", sum(doc2_cache.values()))
    factor = dist._cosAngle_(doc1_cache, doc2_cache)
    if factor > 1: print("The documents are disimilar by factor:", math.floor(factor)) # applied floor to not let values exceed 1.
    else: print("The documents are similar by factor: {}".format(factor))
    end = time()
    print("The time taken is:", (end-start)*1000, "miliseconds")
