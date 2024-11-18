"use client";

import { cn } from "@/lib/utils";

export default function Display({
  children,
  className,
}: {
  children: React.ReactNode;
  className?: string;
}) {
  return (
    <div
      className={cn(
        className,
        "min-h-[100px] border p-4 mb-2 bg-foreground/[2%] rounded-md"
      )}
    >
      {children}
    </div>
  );
}
