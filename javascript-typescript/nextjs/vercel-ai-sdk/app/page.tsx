"use client";

import CallFunctions from "@/components/call-functions";
import CallFunctionsInParallel from "@/components/call-functions-parallel";
import GenerateChatCompletion from "@/components/generate-chat-completion";
import GenerateStructureData from "@/components/generate-structure-data";
import GenerateText from "@/components/generate-text";
import StreamChatCompletion from "@/components/stream-chat-completion";
import StreamTextGeneration from "@/components/stream-text-generation";
import StreamingObjectGeneration from "@/components/streaming-object-generation";
import { Tabs, TabsContent, TabsList, TabsTrigger } from "@/components/ui/tabs";
import { Button } from "@/components/ui/button";
import Link from "next/link";

export default function Home() {
  return (
    <div className="flex flex-col m-1 gap-10">
      <h1 className="text-3xl font-bold m-4 text-center">Vercel AI SDK</h1>
      <Tabs defaultValue="basic">
        <TabsList>
          <TabsTrigger value="basic">Basic</TabsTrigger>
          <TabsTrigger value="chat">Chat</TabsTrigger>
          <TabsTrigger value="tools">Tools</TabsTrigger>
          <TabsTrigger value="state-management">State Management</TabsTrigger>
          <TabsTrigger value="gen-ui">Generative User Interface</TabsTrigger>
        </TabsList>
        <TabsContent value="basic">
          <div>
            <GenerateText />
            <StreamTextGeneration />
            <GenerateStructureData />
            <StreamingObjectGeneration />
          </div>
        </TabsContent>
        <TabsContent value="chat">
          <div>
            <GenerateChatCompletion />
            <StreamChatCompletion />
          </div>
        </TabsContent>
        <TabsContent value="tools">
          <div>
            <CallFunctions />
            <CallFunctionsInParallel />
          </div>
        </TabsContent>
        <TabsContent value="state-management">
          <div className="flex items-center justify-center h-[calc(100vh-160px)] ">
            <Button asChild>
              <Link href="/chat">State Management</Link>
            </Button>
          </div>
        </TabsContent>
        <TabsContent value="gen-ui">
          <div className="flex items-center justify-center h-[calc(100vh-160px)] ">
            <Button asChild>
              <Link href="/chat-gen-ui">Gen UI</Link>
            </Button>
          </div>
        </TabsContent>
      </Tabs>
    </div>
  );
}
