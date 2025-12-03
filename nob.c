#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

#define JIM_IMPLEMENTATION
#include "jim.h"

bool find_challenges(const char *root, File_Paths *out_paths) {
    bool result = true;

    File_Paths file_paths = {0};
    if (!read_entire_dir(root, &file_paths)) return_defer(false);

    da_foreach(const char *, file_name, &file_paths) {
        File_Type file_type = get_file_type(*file_name);
        NOB_ASSERT(file_type >= 0);

        String_View file_name_sv = sv_from_cstr(*file_name);

        if (file_type == FILE_DIRECTORY && sv_starts_with(file_name_sv, sv_from_cstr("challenge"))) {
            // `*file_name` points to the temp buffer
            da_append(out_paths, *file_name);
        }
    }

defer:
    if (file_paths.items) da_free(file_paths);
    return result;
}

int main(int argc, char **argv) {
    int result = 0;
    // This is such that you don't have to recompile this file after bootstrapping
    NOB_GO_REBUILD_URSELF(argc, argv);

    File_Paths challenges = {0};
    if (!find_challenges("./", &challenges)) return_defer(-1);

    Jim jim = {};

    jim_array_begin(&jim);
    String_Builder instructions = {0};
    String_Builder instructions_file_path = {0};
    da_foreach(const char *, challenge, &challenges) {
        instructions.count = 0;
        instructions_file_path.count = 0;
        jim_object_begin(&jim);

        sb_appendf(&instructions_file_path, "%s/instructions.md", *challenge);
        sb_append_null(&instructions_file_path);
        read_entire_file(instructions_file_path.items, &instructions);

        String_View instructions_sv = sb_to_sv(instructions);

        NOB_ASSERT(sv_starts_with(instructions_sv, sv_from_cstr("# ")));
        sv_chop_left(&instructions_sv, 2); // remove "# "
        String_View heading = sv_chop_by_delim(&instructions_sv, '\n');

        NOB_ASSERT(sv_starts_with(instructions_sv, sv_from_cstr("Dated: ")));
        sv_chop_left(&instructions_sv, 7); // remove "Dated: "
        String_View date = sv_chop_by_delim(&instructions_sv, '\n');

        NOB_ASSERT(sv_starts_with(instructions_sv, sv_from_cstr("\n")));
        sv_chop_left(&instructions_sv, 1); // remove "\n"

        size_t i = 0;
        while (i < instructions_sv.count) {
            if (instructions_sv.data[i] == '\n') {
                if (i + 1 == instructions_sv.count || instructions_sv.data[i + 1] == '\n') {
                    break;
                }
                char *newline = (char *)instructions_sv.data + i;
                *newline = ' ';
            }
            i++;
        }
        String_View description = sv_chop_left(&instructions_sv, i);

        jim_member_key(&jim, "dir");
        jim_string(&jim, *challenge);

        jim_member_key(&jim, "heading");
        jim_string_sized(&jim, heading.data, heading.count);

        jim_member_key(&jim, "date");
        jim_string_sized(&jim, date.data, date.count);

        jim_member_key(&jim, "description");
        jim_string_sized(&jim, description.data, description.count);

        jim_object_end(&jim);
    }
    jim_array_end(&jim);

    write_entire_file("challenges.json", jim.sink, jim.sink_count);

defer:
    //let the kernel handle memory cleanup hehehehehe
    //if (challenges.items) da_free(challenges);
    //if (instructions.data) sb_free(&instructions);
    //if (instructions_file_path.data) sb_free(&instructions_file_path);
    //if (jim.sink) {
    //    free(jim.sink);

    //    NOB_ASSERT(jim.scopes);
    //    free(jim.scopes);
    //}

    return result;
}
