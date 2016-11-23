

class your_range:

    def __init__(self, n):
        self.i = 0
        self.n = n
    def __iter__(self): # ci serve per creare una classe iterabile (iterator)
        return self

    def some_useful_function(self):
        print "some"

    def next(self):
        if self.i < self.n:
            i = self.i
            self.i += 1
            #return i
            return self
        else:
            raise StopIteration()


if __name__ == "__main__":

    x = your_range(5)
    x.some_useful_function()
    # print "before looping", x.next()
    # for i in x:
    #     print "looping", i
    # print x.next()
    #print sum(x)

    for it in x:
        #print it
        it.some_useful_function()
