using MMR.Randomizer.Models.Settings;
using System.Collections.Generic;
using System.Text.Encodings.Web;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace MMR.Randomizer.Models
{
    public class LogicFile
    {
        public int Version { get; set; }
        public List<JsonFormatLogicItem> Logic { get; set; }

        public override string ToString()
        {
            return JsonSerializer.Serialize(this, _jsonSerializerOptions);
        }

        public static LogicFile FromJson(string json)
        {
            return JsonSerializer.Deserialize<LogicFile>(json, _jsonSerializerOptions);
        }

        private readonly static JsonSerializerOptions _jsonSerializerOptions = new JsonSerializerOptions
        {
            Encoder = JavaScriptEncoder.UnsafeRelaxedJsonEscaping,
            IgnoreReadOnlyFields = true,
            IgnoreReadOnlyProperties = true,
            DefaultIgnoreCondition = JsonIgnoreCondition.WhenWritingNull,
            WriteIndented = true,
            Converters =
            {
                new JsonColorConverter(),
                new JsonStringEnumConverter(),
            }
        };
    }
}
