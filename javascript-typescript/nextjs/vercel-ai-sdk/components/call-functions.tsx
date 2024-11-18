import { useState } from "react";
import { Button } from "./ui/button";
import { getAnswer } from "@/app/actions/basic";
import Display from "./ui/display";
import { Message } from "@/lib/types";
import { Input } from "./ui/input";
import ChatBox from "./ui/chat-box";
import { continueConversation } from "@/app/actions/call-functions";

export default function CallFunctions() {
  const [conversation, setConversation] = useState<Message[]>([]);
  const [input, setInput] = useState<string>("");

  return (
    <ChatBox headerLabel="Call Functions">
      <Display>
        {conversation.map((message, index) => (
          <div key={index}>
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
            const { messages } = await continueConversation([
              ...conversation,
              { role: "user", content: input },
            ]);
            setInput("");

            setConversation(messages);
          }}
          className=""
        >
          Send Message
        </Button>
      </div>
    </ChatBox>
  );
}
