"use client";

import { useChat } from "ai/react";
import { Input } from "./ui/input";

export default function Chat() {
  const { messages, input, handleInputChange, handleSubmit } = useChat();

  return (
    <div>
      {messages.map((m) => (
        <div key={m.id}>
          {m.role}: {m.content}
        </div>
      ))}

      <form onSubmit={handleSubmit}>
        <label>
          Say something...
          <Input value={input} onChange={handleInputChange} />
        </label>
      </form>
    </div>
  );
}
