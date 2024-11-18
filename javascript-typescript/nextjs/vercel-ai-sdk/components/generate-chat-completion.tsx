"use client";

import { useState } from "react";
import { Card } from "./ui/card";
import { Input } from "./ui/input";
import { Button } from "./ui/button";
import { continueConversation } from "@/app/actions/chat";
import { Message } from "@/lib/types";
import Display from "./ui/display";
import ChatBox from "./ui/chat-box";

export default function GenerateChatCompletion() {
  const [conversation, setConversation] = useState<Message[]>([]);
  const [input, setInput] = useState<string>("");
  return (
    <ChatBox headerLabel="Generate Chat Completion">
      <Display>
        {conversation.map((message, index) => (
          <div key={index} className="p-2">
            {message.role}: {message.content}
          </div>
        ))}
      </Display>

      <div className="flex flex-col gap-2">
        <Input
          type="text"
          value={input}
          placeholder="Type a message..."
          onChange={(event) => {
            setInput(event.target.value);
          }}
        />
        <Button
          variant="outline"
          onClick={async () => {
            const { messages } = await continueConversation([
              ...conversation,
              { role: "user", content: input },
            ]);

            setConversation(messages);
            setInput("");
          }}
          className="max-w-[200px] justify-self-center mx-auto"
        >
          Send Message
        </Button>
      </div>
    </ChatBox>
  );
}
