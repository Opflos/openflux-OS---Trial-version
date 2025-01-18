#include "devices.h"

#define MAX_DEVICES 100
#define DEVICE_NAME_LENGTH 20

struct device {
    char name[DEVICE_NAME_LENGTH];
    int type;
    int status;
};

struct device devices[MAX_DEVICES];
int device_count = 0;

void initialize_devices() {
    device_count = 0;
}

void add_device(const char* name, int type) {
    if (device_count >= MAX_DEVICES) return;
    struct device* new_device = &devices[device_count++];
    for (int i = 0; i < DEVICE_NAME_LENGTH; i++) {
        new_device->name[i] = name[i];
        if (name[i] == '\0') break;
    }
    new_device->type = type;
    new_device->status = 1;
}

void list_devices() {
    for (int i = 0; i < device_count; i++) {
        print_string("Device: ");
        print_string(devices[i].name);
        print_string(" Type: ");
        print_number(devices[i].type);
        print_string(" Status: ");
        print_number(devices[i].status);
        print_string("\n");
    }
}
