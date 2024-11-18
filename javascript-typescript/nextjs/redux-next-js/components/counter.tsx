"use client";

import {
  decrement,
  increment,
  incrementAsync,
  incrementByAmount,
  selectCount,
} from "@lib/store/counterSlice";
import { useAppDispatch, useAppSelector } from "@lib/store/hooks";
import { fetchUserById } from "@lib/store/userSlice";
import Image from "next/image";
import { useEffect, useState } from "react";

function Counter() {
  const [input, setInput] = useState("");
  const count = useAppSelector((state) => state.counter.value);
  const user = useAppSelector((state) => state.user);

  // another way to get count
  const count2 = useAppSelector(selectCount);

  const dispatch = useAppDispatch();

  useEffect(() => {
    const userId = 5;
    dispatch(fetchUserById(userId));
  }, [dispatch]);

  return (
    <div className="grid h-screen place-content-center gap-2">
      <div className="flex items-center justify-center ">
        <button className="w-12" onClick={() => dispatch(increment())}>
          +
        </button>
        <div className="flex">
          <p className="flex h-10 w-24 items-center justify-center rounded-md border border-gray-700 ">
            count: {count}
          </p>
          <p className="flex h-10 w-24 items-center justify-center rounded-md border border-gray-700 ">
            count2: {count}
          </p>
        </div>
        <button className="w-12" onClick={() => dispatch(decrement())}>
          -
        </button>
      </div>
      <div>
        <input
          name="input"
          value={input}
          onChange={(e) => setInput(e.target.value)}
        />
        <button onClick={() => dispatch(incrementByAmount(Number(input)))}>
          Add Amount
        </button>
        <button onClick={() => dispatch(incrementAsync(Number(input)))}>
          Add Async
        </button>
      </div>
      <div>
        <h2>Name: {user.name}</h2>
        <p>id: {user.id}</p>
        {user.avatar && (
          <Image
            src={user.avatar}
            alt="pic"
            width={200}
            height={200}
            priority
          />
        )}
      </div>
    </div>
  );
}

export default Counter;
