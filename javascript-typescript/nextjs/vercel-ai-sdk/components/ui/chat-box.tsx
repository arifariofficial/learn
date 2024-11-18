import { cn } from "@/lib/utils";

interface ChatBoxProps {
  children: React.ReactNode;
  className?: string;
  headerLabel?: string;
  description?: string;
}
export default function ChatBox({
  children,
  className,
  headerLabel,
  description,
}: ChatBoxProps) {
  return (
    <div
      className={cn(
        className,
        "flex flex-col min-h-[100px] border p-2 gap-2 max-w-7xl mx-auto w-full my-4"
      )}
    >
      <h1 className="justify-self-center mx-auto text-2xl font-bold">{headerLabel}</h1>
      <p className="text-muted-foreground text-sm mx-8 mb-6">{description}</p>
      {children}
    </div>
  );
}
