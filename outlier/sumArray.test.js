const sumArray = require("./index");

test("sumArray returns the correct sum", () => {
	expect(sumArray("3,4,5,6")).toBe(18);
	expect(sumArray("1,2,3")).toBe(6);
	expect(sumArray("10,20,30")).toBe(60);
});

test("sumArray throws error for invalid input", () => {
	expect(() => sumArray("1,2,three")).toThrow("Please enter valid numbers.");
	expect(() => sumArray("")).toThrow("No input provided.");
});
