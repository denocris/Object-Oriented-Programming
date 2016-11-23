class DataHandler:
    def __init__(self,n):
        self.i = 0
        self.n = n
    def __iter__(self):
        return self

    def print_content(self):
        print "--------"
        print self.i
        print self.n
        print "--------"

    def next(self):
        if self.i < self.n:
            i = self.i
            self.i+=1
            return self
        else:
            #self.i = 0
            raise StopIteration()

class DataUser:
    def reinit(self,dh):
        self.__data_handler = dh

    def manipulation_on_data(self):
        print "manipulated data: ",(self.__data_handler.i)**2


if __name__ == "__main__":
    some_handler = DataHandler(5)
    some_user = DataUser()

    for it in some_handler:
        some_user.reinit(it)
        it.print_content()
        some_user.manipulation_on_data()
        it.print_content()
