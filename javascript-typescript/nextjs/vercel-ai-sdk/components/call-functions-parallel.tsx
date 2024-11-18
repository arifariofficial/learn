import { useState } from "react";
import ChatBox from "./ui/chat-box";
import { Message } from "@/lib/types";
import { continueConversation } from "@/app/actions/call-functions-parallel";
import { Input } from "./ui/input";
import { Button } from "./ui/button";
import Display from "./ui/display";

export default function CallFunctionsInParallel() {
  const [conversation, setConversation] = useState<Message[]>([]);
  const [input, setInput] = useState<string>("");
  return (
    <ChatBox headerLabel="Call Functions in Parallel">
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

            setConversation(messages);
          }}
        >
          Send Message
        </Button>
      </div>
    </ChatBox>
  );
}
