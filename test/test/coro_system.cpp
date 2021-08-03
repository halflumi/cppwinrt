// Intentionally not using pch...
#include "catch.hpp"

// Only need winrt/Windows.System.h for resume_foreground DispatcherQueue support
#include "winrt/Windows.System.h"

using namespace winrt;
using namespace Windows::System;

namespace winrt::Windows::System
{
    inline auto operator co_await(Windows::System::DispatcherQueue const& dispatcher)
    {
        return resume_foreground(dispatcher);
    }
}

namespace
{
    fire_and_forget Async(DispatcherQueue queue)
    {
        co_await resume_foreground(queue);

        co_await queue;
    }
}

TEST_CASE("coro_system")
{
    auto controller = DispatcherQueueController::CreateOnDedicatedThread();
    Async(controller.DispatcherQueue());
}
