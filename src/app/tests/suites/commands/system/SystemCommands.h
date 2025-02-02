/*
 *   Copyright (c) 2022 Project CHIP Authors
 *   All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#pragma once

#include <lib/support/CodeUtils.h>
#include <lib/support/StringBuilder.h>

class SystemCommands
{
public:
    SystemCommands(){};
    virtual ~SystemCommands(){};

    virtual CHIP_ERROR ContinueOnChipMainThread(CHIP_ERROR err) = 0;

    CHIP_ERROR Start(uint16_t discriminator = 0xFFFF, uint16_t port = CHIP_PORT, const char * kvs = nullptr,
                     const char * registerKey = "default");
    CHIP_ERROR Stop(const char * registerKey = "default");
    CHIP_ERROR Reboot(const char * registerKey = "default");
    CHIP_ERROR FactoryReset(const char * registerKey = "default");

private:
    CHIP_ERROR RunInternal(const char * command);
    CHIP_ERROR CreateCommonCommandArgs(chip::StringBuilderBase & builder, const char * scriptDir, const char * scriptName,
                                       const char * registerKey, uint16_t discriminator, uint16_t port, const char * kvs);
};
