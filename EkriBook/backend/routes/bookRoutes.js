const express = require("express");
const router = express.Router();
const {
    getBooks,
    getBook,
    createBook,
    updateBook,
    deleteBook
} = require("../controllers/bookController");

router.get('/', getBooks);
router.get('/:title', getBook);
router.post('/', createBook);
router.put('/:title', updateBook);
router.delete('/:title', deleteBook);

module.exports = router;
