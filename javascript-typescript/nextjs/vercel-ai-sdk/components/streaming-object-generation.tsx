import { useState } from "react";
import { Button } from "./ui/button";
import { readStreamableValue } from "ai/rsc";
import { generate2 } from "@/app/actions/basic";
import Display from "./ui/display";
import ChatBox from "./ui/chat-box";

export default function StreamingObjectGeneration() {
  const [generation, setGeneration] = useState<string>("");
  return (
    <ChatBox headerLabel="Streaming Object Generation">
      <Button
        variant="outline"
        onClick={async () => {
          const { object } = await generate2("Messages during finals week.");

          for await (const partialObject of readStreamableValue(object)) {
            if (partialObject) {
              setGeneration(JSON.stringify(partialObject.notifications, null, 2));
            }
          }
        }}
        className="justify-self-center mx-auto"
      >
        Ask
      </Button>
      <Display>
        <pre>{generation}</pre>
      </Display>
    </ChatBox>
  );
}
