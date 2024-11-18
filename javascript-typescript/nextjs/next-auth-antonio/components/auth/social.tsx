"use client";

import { FcGoogle } from "react-icons/fc";
import { Button } from "../ui/button";
import { FaGithub } from "react-icons/fa";
import { signIn } from "next-auth/react";
import { DEFAULT_LOGIN_REDIRECT } from "@/route";

export const Social = () => {
  const onClick = (provider: "google" | "github") => {
    signIn(provider, {
      callbackUrl: "/settings",
    });
  };

  return (
    <div className="flex w-full items-center gap-x-2">
      <Button size={"lg"} variant={"outline"} className="w-full">
        <FcGoogle className="h-5 w-5" />
        <span className="mx-4">Google</span>
      </Button>
      <Button
        variant={"outline"}
        className="w-full"
        onClick={() => onClick("github")}
      >
        <FaGithub className="h-5 w-5" />
        <span className="mx-4">Github</span>
      </Button>
    </div>
  );
};
