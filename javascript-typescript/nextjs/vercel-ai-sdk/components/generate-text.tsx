import { useState } from "react";
import { Button } from "./ui/button";
import { getAnswer } from "@/app/actions/basic";
import Display from "./ui/display";
import ChatBox from "./ui/chat-box";

export default function GenerateText() {
  const [generation, setGeneration] = useState<string>("");
  return (
    <ChatBox
      headerLabel="Generate Text"
      description="Generates text on based on a given question 'Why the sky is blue?' When the answer button is clicked, it calls a server action called 'getAnswer' which returns a text response. The text response is then displayed on the screen."
    >
      <Button
        variant="outline"
        onClick={async () => {
          const { text } = await getAnswer("Why is the sky blue?");
          setGeneration(text);
        }}
        className="max-w-[200px] justify-self-center mx-auto"
      >
        Answer
      </Button>
      <Display>{generation}</Display>
    </ChatBox>
  );
}
