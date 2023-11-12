const asyncHandler = require("express-async-handler");
const Book = require("../models/book_model");

// Get all books
exports.getBooks = asyncHandler(async (req, res) => {
    const books = await Book.find();
    res.status(200).json(books);
});

// Get a single book by title
exports.getBook = asyncHandler(async (req, res) => {
    const book = await Book.findOne({ title: req.params.title });
    if (book) {
        res.status(200).json(book);
    } else {
        res.status(404).json({ message: "Book not found" });
    }
});

// Create a new book
exports.createBook = asyncHandler(async (req, res) => {
    const { title, author, rentPrice } = req.body;

    // Basic validation
    if (!title || !author || !rentPrice) {
        res.status(400).json({ message: "Please include all fields" });
        return;
    }

    // Check for existing book
    const bookExists = await Book.findOne({ title });
    if (bookExists) {
        res.status(400).json({ message: "Book already exists" });
        return;
    }

    // Create book
    const book = new Book({ title, author, rentPrice });
    await book.save();
    res.status(201).json(book);
});

// Update a book
exports.updateBook = asyncHandler(async (req, res) => {
    const book = await Book.findOneAndUpdate({ title: req.params.title }, req.body, { new: true });
    if (book) {
        res.status(200).json(book);
    } else {
        res.status(404).json({ message: "Book not found" });
    }
});

// Delete a book
exports.deleteBook = asyncHandler(async (req, res) => {
    const book = await Book.findOneAndDelete({ title: req.params.title });
    if (book) {
        res.status(200).json({ message: `Book ${book.title} deleted successfully` });
    } else {
        res.status(404).json({ message: "Book not found" });
    }
});
