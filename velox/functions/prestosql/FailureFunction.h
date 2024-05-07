/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "velox/functions/Macros.h"
#include "velox/functions/prestosql/types/JsonType.h"

namespace facebook::velox::functions {
template <typename TExecParams>
struct FailFunction {
  VELOX_DEFINE_FUNCTION_TYPES(TExecParams);

  FOLLY_ALWAYS_INLINE void call(
      out_type<UnknownValue> /*out*/,
      const int32_t /*errCode*/,
      const arg_type<Varchar>& errMsg) {
    VELOX_USER_FAIL("Fail Function: {}", errMsg);
  }

  FOLLY_ALWAYS_INLINE void call(
      out_type<UnknownValue> /*out*/,
      const arg_type<Varchar>& errMsg) {
    VELOX_USER_FAIL(errMsg);
  }
};
} // namespace facebook::velox::functions
