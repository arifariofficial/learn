const handleRequest = (req) => {
    const url = new URL(req.url);
    const params = url.searchParams;

    let message = "Not here.";

    if (url.pathname === "/" && req.method === "GET") {
        message = "Hi there!";
    } else if (url.pathname === "/congrats" && req.method === "GET") {
        message = `Congrats, ${params.get("heroOfTheDay")}!`;
    } else if (url.pathname === "/lol" && req.method === "DIDNOT") {
        message = `What kind of tree fits in your hand? A palm tree.`;
    }

    return new Response(message);
};

Deno.serve(handleRequest);
