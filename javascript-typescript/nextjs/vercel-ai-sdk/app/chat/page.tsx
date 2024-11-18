"use client";

import { useState } from "react";
import { useActions, useUIState } from "ai/rsc";
import { nanoid } from "nanoid";
import ChatBox from "@/components/ui/chat-box";
import { Input } from "@/components/ui/input";
import Display from "@/components/ui/display";
import { Button } from "@/components/ui/button";
import Link from "next/link";
import { ClientMessage } from "@/lib/types";

export default function Home() {
  const [input, setInput] = useState<string>("");
  const [conversation, setConversation] = useUIState();
  const { continueConversation } = useActions();

  return (
    <ChatBox>
      <Button className="justify-self-start mb-10">
        <Link href="/">Back</Link>
      </Button>
      <Display className="max-h-[300px] overflow-auto">
        {conversation.map((message: ClientMessage) => (
          <div key={message.id}>
            {message.role}: {message.display}
          </div>
        ))}
      </Display>

      <div className="flex flex-col gap-2">
        <Input
          type="text"
          value={input}
          onChange={(event) => {
            setInput(event.target.value);
          }}
        />
        <div className="flex flex-row w-full justify-between">
          <Button
            onClick={async () => {
              setConversation((currentConversation: ClientMessage[]) => [
                ...currentConversation,
                { id: nanoid(), role: "user", display: input },
              ]);
              setInput("");

              const message = await continueConversation(input);

              setConversation((currentConversation: ClientMessage[]) => [
                ...currentConversation,
                message,
              ]);
            }}
          >
            Send Message
          </Button>
        </div>
      </div>
    </ChatBox>
  );
}
