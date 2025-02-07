/*
 * Copyright (C) 2020-2023 IoT.bzh Company
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

#ifndef SEC_LSM_MANAGER_SECURE_APP_H
#define SEC_LSM_MANAGER_SECURE_APP_H

#include <sys/types.h>

#include "cynagora-interface.h"
#include "limits.h"
#include "paths.h"

typedef struct secure_app {
    char id[SEC_LSM_MANAGER_MAX_SIZE_ID];
    char id_underscore[SEC_LSM_MANAGER_MAX_SIZE_ID];
    char label[SEC_LSM_MANAGER_MAX_SIZE_LABEL];
    permission_set_t permission_set;
    path_set_t path_set;
    bool error_flag;
} secure_app_t;

/**
 * @brief Create the secure app and init it
 *
 * This secure app need to be destroy at the end
 * if the function succeeded
 *
 * @param[out] pointer to secure_app handler
 * @return 0 in case of success or a negative -errno value
 */
extern int create_secure_app(secure_app_t **pointer) __wur;

/**
 * @brief Free id, paths and permissions
 * The pointer is not free
 *
 * @param[in] secure_app handler
 */
extern void clear_secure_app(secure_app_t *secure_app) __nonnull();

/**
 * @brief Destroy the secure app
 * Free secure app handler and content
 *
 * @param[in] secure_app handler
 */
extern void destroy_secure_app(secure_app_t *secure_app) __nonnull();

/**
 * @brief Alloc and copy id in secure app
 *
 * @param[in] secure_app handler
 * @param[in] id The id to copy
 * @return 0 in case of success or a negative -errno value
 */
extern int secure_app_set_id(secure_app_t *secure_app, const char *id) __wur __nonnull();

/**
 * @brief Add a new policy in policies field
 *
 * @param[in] secure_app handler
 * @param[in] permission The permission to add
 * @return 0 in case of success or a negative -errno value
 */
extern int secure_app_add_permission(secure_app_t *secure_app, const char *permission) __wur __nonnull();

/**
 * @brief Add a new path in paths field
 *
 * @param[in] secure_app handler
 * @param[in] path The path to add
 * @param[in] path_type The path type to add
 * @return 0 in case of success or a negative -errno value
 */
extern int secure_app_add_path(secure_app_t *secure_app, const char *path, enum path_type path_type) __wur __nonnull();

/**
 * @brief Set error_flag
 * The secure_app can't be installed after
 * You need to clear to return in create state
 */
extern void raise_error_flag(secure_app_t *secure_app) __nonnull();

#endif
