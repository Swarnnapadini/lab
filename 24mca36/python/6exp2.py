class Publisher:
    def __init__(self, publisher_id, publisher_name):
        self.publisher_id = publisher_id
        self.publisher_name = publisher_name

    def display(self):
        print(f"Publisher ID: {self.publisher_id}")
        print(f"Publisher Name: {self.publisher_name}")


class Book(Publisher):
    def __init__(self, publisher_id, publisher_name, title, author):
        super().__init__(publisher_id, publisher_name)
        self.title = title
        self.author = author

    def display(self):
        super().display()
        print(f"Book Title: {self.title}")
        print(f"Author: {self.author}")


class Python(Book):
    def __init__(self, publisher_id, publisher_name, title, author, price, no_of_pages):
        super().__init__(publisher_id, publisher_name, title, author)
        self.price = price
        self.no_of_pages = no_of_pages

    def display(self):
        super().display()
        print(f"Book Price: {self.price}")
        print(f"Number of Pages: {self.no_of_pages}")


# Input details for the Python book
print("Enter the details for the Python book:")
publisher_id = int(input("Enter publisher ID: "))
publisher_name = input("Enter publisher name: ")
title = input("Enter the title of the book: ")
author = input("Enter the author name: ")
price = int(input("Enter the price: "))
no_of_pages = int(input("Enter the number of pages: "))

# Create an instance of the Python class
python_book = Python(
    publisher_id=publisher_id,
    publisher_name=publisher_name,
    title=title,
    author=author,
    price=price,
    no_of_pages=no_of_pages
)

# Display book information
print("\nPython Book Information:")
python_book.display()
