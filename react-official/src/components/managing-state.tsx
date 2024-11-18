import { useState } from "react";
import { Button } from "./ui/button";

// Reacting to input with state
function Form() {
	const [answer, setAnswer] = useState("");
	const [error, setError] = useState(null);
	const [status, setStatus] = useState("typing");

	if (status === "success") {
		return <h1>That's right!</h1>;
	}

	async function handleSubmit(e) {
		e.preventDefault();
		setStatus("submitting");
		try {
			await submitForm(answer);
			setStatus("success");
		} catch (err) {
			setStatus("typing");
			setError(err);
		}
	}

 function handleTextareaChange(e: React.ChangeEvent<HTMLTextAreaElement>) {
 	setAnswer(e.target.value);
 }

	return (
		<div className="flex flex-col w-[400px] mx-auto gap-2 items-center justify-center">
			<h2>City quiz</h2>
			<p>In which city is there a billboard that turns air into drinkable water?</p>
			<form onSubmit={handleSubmit} className="w-full flex flex-col">
				<textarea
					title="city-quiz-input"
					value={answer}
					onChange={handleTextareaChange}
					disabled={status === "submitting"}
					className="border w-full"
				/>
				<br />
				<Button
					variant="outline"
					disabled={answer.length === 0 || status === "submitting"}
					className="place-self-center"
				>
					Submit
				</Button>
				{error !== null && <p className="Error">{error.message}</p>}
			</form>
		</div>
	);
}

function submitForm(answer) {
	// Pretend it's hitting the network.
	return new Promise((resolve, reject) => {
		setTimeout(() => {
			let shouldError = answer.toLowerCase() !== "lima";
			if (shouldError) {
				reject(new Error("Good guess but a wrong answer. Try again!"));
			} else {
				resolve();
			}
		}, 1500);
	});
}

const ManagingState = () => {
	return (
		<div className="flex flex-col gap-8 justify-center items-center mb-20">
			<h1 id="managingState" className="text-2xl font-bold">
				Managing State
			</h1>
			<section>
				<h1 className="text-lg font-bold">Reacting to input with state </h1>
				<Form />
			</section>
		</div>
	);
};
export default ManagingState;
