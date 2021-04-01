/*
 * Copyright (C) 2020-2021 IoT.bzh Company
 * Author: Arthur Guyader <arthur.guyader@iot.bzh>
 *
 * $RP_BEGIN_LICENSE$
 * Commercial License Usage
 *  Licensees holding valid commercial IoT.bzh licenses may use this file in
 *  accordance with the commercial license agreement provided with the
 *  Software or, alternatively, in accordance with the terms contained in
 *  a written agreement between you and The IoT.bzh Company. For licensing terms
 *  and conditions see https://www.iot.bzh/terms-conditions. For further
 *  information use the contact form at https://www.iot.bzh/contact.
 *
 * GNU General Public License Usage
 *  Alternatively, this file may be used under the terms of the GNU General
 *  Public license version 3. This license is as published by the Free Software
 *  Foundation and appearing in the file LICENSE.GPLv3 included in the packaging
 *  of this file. Please review the following information to ensure the GNU
 *  General Public License requirements will be met
 *  https://www.gnu.org/licenses/gpl-3.0.html.
 * $RP_END_LICENSE$
 */

#ifndef SEC_LSM_MANAGER_SELINUX_LABEL_H
#define SEC_LSM_MANAGER_SELINUX_LABEL_H

#ifndef SIMULATE_SELINUX
#include <selinux/selinux.h>
#include <semanage/semanage.h>
#else
#include "simulation/selinux/selinux.h"
#endif

#include <stdbool.h>

#include "paths.h"

typedef struct path_type_definitions {
    char *label;
} path_type_definitions_t;

/**
 * @brief Check if selinux is enabled
 *
 * @return true if enabled
 * @return false if not
 */
bool selinux_enabled() __wur;

/**
 * @brief Init differents labels for all path type
 *
 * @param[in] path_type_definitions Array definition to complete
 * @param[in] id to generate label of an application
 *
 * @return 0 in case of success or a negative -errno value
 */
int init_path_type_definitions(path_type_definitions_t path_type_definitions[number_path_type], const char *id) __wur
    __nonnull((2));

/**
 * @brief Free path type definition label
 *
 * @param[in] path_type_definitions Array definition to free
 */
void free_path_type_definitions(path_type_definitions_t path_type_definitions[number_path_type]) __nonnull();
#endif
