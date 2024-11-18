"use client";

import { Card, CardContent, CardFooter, CardHeader } from "../ui/card";
import { BackBotton } from "./back-button";
import { Header } from "./header";
import { Social } from "./social";

interface CardWrapperProps {
  children: React.ReactNode;
  headerLabel: string;
  backButtonLabel: string;
  backButtonHref: string;
  showLocal?: boolean;
}

export const CardWrapper = ({
  children,
  headerLabel,
  backButtonLabel,
  backButtonHref,
  showLocal,
}: CardWrapperProps) => {
  return (
    <Card className="shadow-md- w-[400px]">
      <CardHeader>
        <Header label={headerLabel} />
      </CardHeader>
      <CardContent>{children}</CardContent>
      {showLocal && (
        <CardFooter>
          <Social />
        </CardFooter>
      )}
      <CardFooter>
        <BackBotton label={backButtonLabel} href={backButtonHref}></BackBotton>
      </CardFooter>
    </Card>
  );
};
