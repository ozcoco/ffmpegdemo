#include <libavutil/avutil.h>
#include <libavutil/log.h>
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
#include <libavutil/error.h>


int main() {

    av_log_set_level(AV_LOG_DEBUG);

    av_log(NULL, AV_LOG_INFO, "xxxxxxx!!!");

    AVIODirContext *context = NULL;

    int ret = avio_open_dir(&context, "/home/oz/Pictures", NULL);

    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "%s", av_err2str(ret));
    }

    AVIODirEntry *entry = NULL;

    while (1) {

        avio_read_dir(context, &entry);

        if (!entry)
            break;

        av_log(NULL, AV_LOG_ERROR, "\nname:%s\tsize:%ld", entry->name, entry->size);

        avio_free_directory_entry(&entry);
    }

    avio_close_dir(&context);


    return 0;
}