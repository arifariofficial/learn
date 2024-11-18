"use server";

import { createAI, getAIState, getMutableAIState, streamUI } from "ai/rsc";
import { openai } from "@ai-sdk/openai";
import { nanoid } from "nanoid";
import { ClientMessage, ServerMessage } from "@/lib/types";
import { saveChat } from "@/app/db/chat";

export async function continueConversation(input: string): Promise<ClientMessage> {
  "use server";

  const history = getMutableAIState();

  const result = await streamUI({
    model: openai("gpt-3.5-turbo"),
    messages: [...history.get(), { role: "user", content: input }],
    text: ({ content, done }) => {
      if (done) {
        history.done((messages: ServerMessage[]) => [
          ...messages,
          { role: "assistant", content },
        ]);
      }

      return <div>{content}</div>;
    },
  });

  return {
    id: nanoid(),
    role: "assistant",
    display: result.value,
  };
}

export const AI = createAI<ServerMessage[], ClientMessage[]>({
  actions: {
    continueConversation,
  },
  onSetAIState: async ({ state, done }: { state: ServerMessage[]; done: boolean }) => {
    "use server";

    if (done) {
      saveChat(state);
    }
  },
  onGetUIState: async () => {
    "use server";

    const history: ServerMessage[] = getAIState();

    return history.map(({ role, content }) => ({
      id: nanoid(),
      role,
      display: content,
    }));
  },
});
