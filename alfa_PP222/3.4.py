class StringHandler:
    def __init__(self):
        self.s = ""

    def getString(self):
        self.s = input()

    def printString(self):
        print(self.s.upper())


if __name__ == "__main__":
    handler = StringHandler()
    handler.getString()
    handler.printString()