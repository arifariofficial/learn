### Story

The assignment template comes with an application that returns a short story with the main character being called Linus. Modify the application so that the name of the main character can be given as the request parameter name. If the request parameter is not given, use Linus as the name. When completed, test the application locally and return it here.

```javascript
import { Hono } from "https://deno.land/x/hono@v3.12.11/mod.ts";

const app = new Hono();

app.get("/", (c) => {
    let name = c.req.query("name") ?? "Linus";
    return c.text(
        `Once upon a time, there was a young kid called ${name}. ${name} was happy.`
    );
});

Deno.serve(app.fetch);

```

### Calculator revisited

Similar to practicing request parameters with Vanilla Deno, using the template code given as a part of the assignment, create a calculator application. The application expects three request parameters, 'operation', 'number1', and 'number2'. Using the operation, that can be either 'sum' or 'difference', the calculator should respond with the operation performed on the parameters 'number1' and 'number2'. For example, if a user makes a request to the address `http://localhost:8000?operation=sum&number1=2&number2=2`, the response should be '4'. Similarly, if the request is made to `http://localhost:8000?operation=difference&number1=8&number2=12`, the response should be `-4`. If one of the parameters is missing, or the operation is not one of the defined ones, the response should be 'Invalid parameters.'. You can assume that the numbers are always given using numeric values. When completed, test the application locally and return it here.
