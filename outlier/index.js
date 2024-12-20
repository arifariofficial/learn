function sumArray(input) {
	if (!input) {
		throw new Error("No input provided.");
	}

	const arr = input.split(",").map(Number);

	if (arr.some(isNaN)) {
		throw new Error("Please enter valid numbers.");
	}

	return arr.reduce((sum, current) => sum + current, 0);
}

module.exports = sumArray;
