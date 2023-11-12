const { constants } = require("../constants");

const errorHandler = (err, req, res, next) => {
    const statusCode = res.statusCode !== 200 ? res.statusCode : 500;
    res.status(statusCode);

    let response = {
        title: "Error",
        message: err.message,
    };

    // Include stack trace if not in production
    if (process.env.NODE_ENV === 'development') {
        response.stack = err.stack;
    }

    switch (statusCode) {
        case constants.VALIDATION_ERROR:
            response.title = "Validation Failed";
            break;
        case constants.UNAUTHORIZED:
            response.title = "Unauthorized";
            break;
        case constants.FORBIDDEN:
            response.title = "Forbidden";
            break;
        case constants.NOT_FOUND:
            response.title = "Not Found";
            break;
        case constants.SERVER_ERROR:
            response.title = "Server Error";
            break;
        default:
            console.log("Unhandled status code:", statusCode);
            break;
    }

    res.json(response);
};

module.exports = errorHandler;
