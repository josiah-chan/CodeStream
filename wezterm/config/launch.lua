local platform = require("utils.platform")()

local options = {
  default_prog = {},
  launch_menu = {},
}

if platform.is_win then
  options.default_prog = { "powershell" }
  options.launch_menu = {
    { label = " PowerShell v1", args = { "powershell" } },
    { label = " Cmd", args = { "cmd" } },
    {
      label = " GitBash",
      args = { "C:\\Program Files\\Git\\bin\\bash.exe" },
    },
    {
      label = " Evan-System",
      args = { "ssh", "evan@172.16.80.159", "-p", "22" },
    },
  }
elseif platform.is_mac then
  options.default_prog = { "/opt/homebrew/bin/fish", "--login" }
  options.launch_menu = {
    { label = " Bash", args = { "bash", "--login" } },
    { label = " Fish", args = { "/opt/homebrew/bin/fish", "--login" } },
    { label = " Nushell", args = { "/opt/homebrew/bin/nu", "--login" } },
    { label = " Zsh", args = { "zsh", "--login" } },
  }
elseif platform.is_linux then
  options.default_prog = { "bash", "--login" }
  options.launch_menu = {
    { label = " Bash", args = { "bash", "--login" } },
    { label = " Fish", args = { "/opt/homebrew/bin/fish", "--login" } },
    { label = " Nushell", args = { "/opt/homebrew/bin/nu", "--login" } },
    { label = " Zsh", args = { "zsh", "--login" } },
  }
end

return options
