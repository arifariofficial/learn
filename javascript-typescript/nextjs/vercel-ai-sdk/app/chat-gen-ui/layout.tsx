import { ServerMessage } from "@/lib/types";
import { getChat } from "../db/chat";
import { AI } from "@/lib/chat/actions-gen-ui";

export default async function ChatLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  // get chat history from database
  const history: ServerMessage[] = (await getChat()) as ServerMessage[];

  return (
    <html lang="en">
      <body className="flex flex-col">
        <AI initialAIState={history} initialUIState={[]}>
          {children}
        </AI>
      </body>
    </html>
  );
}
