import { useState } from "react";
import { Button } from "./ui/button";
import { readStreamableValue } from "ai/rsc";
import { generate } from "@/app/actions/basic";
import Display from "./ui/display";
import ChatBox from "./ui/chat-box";

export default function StreamTextGeneration() {
  const [generation, setGeneration] = useState<string>("");
  return (
    <ChatBox headerLabel="Stream Text Generation">
      <Button
        variant="outline"
        onClick={async () => {
          const { output } = await generate("Why is the sky blue?");

          for await (const delta of readStreamableValue(output)) {
            setGeneration((currentGeneration) => `${currentGeneration}${delta}`);
          }
        }}
        className="justify-self-center mx-auto"
      >
        Ask
      </Button>

      <Display>{generation}</Display>
    </ChatBox>
  );
}
