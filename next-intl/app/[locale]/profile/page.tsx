import { auth } from "@/middlewares/auth";

const ProfilePage = async () => {
	const session = await auth();

	if (!session) {
		return <div>You must be signed in to view this page.</div>;
	}

	console.log(session.user?.email);

	return (
		<div>
			<h1>Profile Page</h1>
			<p>Welcome, {session.user?.name || "User"}!</p>
			<p>Email: {session.user?.email}</p>
		</div>
	);
};

export default ProfilePage;
