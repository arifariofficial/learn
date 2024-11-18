"use client";

import { useState } from "react";
import { readStreamableValue } from "ai/rsc";
import { continueConversation } from "@/app/actions/chat";
import { Card } from "./ui/card";
import { Input } from "./ui/input";
import { Button } from "./ui/button";
import { Message } from "@/lib/types";
import Display from "./ui/display";
import ChatBox from "./ui/chat-box";

export default function StreamChatCompletion() {
  const [conversation, setConversation] = useState<Message[]>([]);
  const [input, setInput] = useState<string>("");

  return (
    <ChatBox headerLabel="Stream Chat Completion">
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
          onChange={(event) => {
            setInput(event.target.value);
          }}
        />
        <Button
          onClick={async () => {
            const { messages, newMessage } = await continueConversation([
              ...conversation,
              { role: "user", content: input },
            ]);
            setInput("");

            let textContent = "";

            for await (const delta of readStreamableValue(newMessage)) {
              textContent = `${textContent}${delta}`;

              setConversation([...messages, { role: "assistant", content: textContent }]);
            }
          }}
        >
          Send Message
        </Button>
      </div>
    </ChatBox>
  );
}
