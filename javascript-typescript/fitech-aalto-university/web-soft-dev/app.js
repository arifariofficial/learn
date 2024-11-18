const handleRequest = (request) => {
  const url = new URL(request.url);
  const params = url.searchParams;

  let title = "princess";
  let name = "Tove";

  if (params.has("title")) {
    title = params.get("title");
  }
  if (params.has("name")) {
    name = params.get("name");
  }

  return new Response(`Once upon a time, there was a ${title} called ${name}.`);
};

Deno.serve(handleRequest);
