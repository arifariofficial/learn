"use client";

import { getNotifications } from "@/app/actions/basic";
import { Button } from "./ui/button";
import { useState } from "react";
import Display from "./ui/display";
import ChatBox from "./ui/chat-box";

export default function GenerateStructureData() {
  const [generation, setGeneration] = useState<string>("");

  return (
    <ChatBox headerLabel="Generate Structure Data">
      <Button
        variant="outline"
        onClick={async () => {
          const { notifications } = await getNotifications(
            "Messages during finals week."
          );

          setGeneration(JSON.stringify(notifications, null, 2));
        }}
        className="justify-self-center mx-auto"
      >
        View Notifications
      </Button>
      <Display>
        <pre>{generation}</pre>
      </Display>
    </ChatBox>
  );
}
