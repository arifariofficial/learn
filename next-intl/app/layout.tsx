import { ReactNode } from "react";

type Props = {
	children: ReactNode;
};

// Since we have a `not-found.tsx` page on the root, a layout file
// is required, even if it's just passing children through.
export default async function RootLayout({ children }: Props) {
	return (
		<html lang="en">
			<body>{children}</body>
		</html>
	);
}