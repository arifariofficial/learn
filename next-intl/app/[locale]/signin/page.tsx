"use client";

import { useState } from "react";
import { signIn } from "next-auth/react";
import { useRouter } from "next/navigation";

const SignInPage = () => {
	const [email, setEmail] = useState("");
	const [password, setPassword] = useState("");
	const [error, setError] = useState("");
	const [loading, setLoading] = useState(false);
	const router = useRouter();

	const handleSignIn = async (e: React.FormEvent) => {
		e.preventDefault();
		setLoading(true);
		setError("");

		const result = await signIn("credentials", {
			redirect: false, // Disable automatic redirects
			email,
			password,
		});

		if (result?.error) {
			setError(result.error); // Display error if sign-in fails
		} else {
			// Redirect to a protected page or homepage on successful login
			router.push("/chat");
		}

		setLoading(false);
	};

	return (
		<div style={{ maxWidth: "400px", margin: "0 auto", padding: "20px" }}>
			<h1>Sign In</h1>
			<form onSubmit={handleSignIn}>
				<div style={{ marginBottom: "10px" }}>
					<label htmlFor="email" style={{ display: "block", marginBottom: "5px" }}>
						Email
					</label>
					<input
						type="text"
						id="email"
						value={email}
						onChange={(e) => setEmail(e.target.value)}
						required
						style={{ width: "100%", padding: "8px", boxSizing: "border-box" }}
					/>
				</div>
				<div style={{ marginBottom: "10px" }}>
					<label htmlFor="password" style={{ display: "block", marginBottom: "5px" }}>
						Password
					</label>
					<input
						type="password"
						id="password"
						value={password}
						onChange={(e) => setPassword(e.target.value)}
						required
						style={{ width: "100%", padding: "8px", boxSizing: "border-box" }}
					/>
				</div>
				{error && <div style={{ color: "red", marginBottom: "10px" }}>{error}</div>}
				<button
					type="submit"
					disabled={loading}
					style={{
						width: "100%",
						padding: "10px",
						backgroundColor: "#0070f3",
						color: "#fff",
						border: "none",
						borderRadius: "4px",
						cursor: "pointer",
					}}
				>
					{loading ? "Signing in..." : "Sign In"}
				</button>
			</form>
		</div>
	);
};

export default SignInPage;
