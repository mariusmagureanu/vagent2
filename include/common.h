#ifndef COMMON_H
#define COMMON_H


struct vadmin_ret {
	unsigned int status;
	char *answer;
};

struct agent_config_t {
	double timeout;
	char *T_arg;
	char *S_arg;
	char *n_arg;
	char *c_arg;
};

struct vadmin_config_t {
	int sock;
	struct ipc_t *ipc;
	int logger;
};

struct agent_core_t {
	struct agent_config_t *config;
	struct agent_plugin_t *plugins;
};
struct agent_plugin_t {
	const char *name;
	void *data;
	struct ipc_t *ipc;
	struct agent_plugin_t *next;
	pthread_t *(*start)(struct agent_core_t *core, const char *name);
	pthread_t *thread;
};

int logd_register(struct agent_core_t *core);


#endif
