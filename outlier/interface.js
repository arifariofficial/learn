const weekday = (function () {
	const names = [
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
	];

	function count() {
		return names.length;
	}

	function name(n) {
		return names[n];
	}

	function number(str) {
		return names.findIndex((el) => el === str);
	}

	return { count, name, number };
})();

var num = 0;

console.log("There are " + weekday.count() + " days in a week.");
console.log(
	"In programming, the index of " + weekday.name(num) + " tends to be " + num + "."
);
