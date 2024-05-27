return
{
  "mfussenegger/nvim-dap",
  dependencies = 
  {
    "nvim-neotest/nvim-nio",
    "rcarriga/nvim-dap-ui"
  },
  
  config = function()
    local dap   = require("dap")
    local dapui = require("dapui")

    require("dapui").setup()

    dap.listeners.before.attach.dapui_config = function()
      dapui.open()
    end
    dap.listeners.before.launch.dapui_config = function()
      dapui.open()
    end
    dap.listeners.before.event_terminated.dapui_config = function()
      dapui.close()
    end
    dap.listeners.before.event_exited.dapui_config = function()
      dapui.close()
    end

    dap.adapters.gdb = 
    {
      type = "executable",
      command = "gdb",
      args = { "-i", "dap"}
    }

    dap.configurations.cpp = 
    {
      {
        name = "gdb",
        type = "gdb",
        request = "launch",
        -- program = "/usr/bin/gdb",
        program = function()
          return vim.fn.input('Path to executable: ', vim.fn.getcwd() .. '/', 'file')
        end,
        cwd = "${workspaceFolder}",
        stopAtBeginningOfMainSubprogram = false,
        console = "integratedTerminal",
      },
    }

    vim.keymap.set('n', '<Leader>db', dap.toggle_breakpoint, {})
    vim.keymap.set('n', '<Leader>dc', dap.continue, {})
    vim.keymap.set('n', '<Leader>dn', dap.step_over, {})
    vim.keymap.set('n', '<Leader>di', dap.step_into, {})
    vim.keymap.set('n', '<Leader>do', dap.step_out, {})

  end,
}
